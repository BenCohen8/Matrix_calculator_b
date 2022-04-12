#include <iostream>
#include <string.h>
#include <vector>
#include <sstream> 
#include "Matrix.hpp"
using namespace std;
using namespace zich;
    //maiking matrix
    zich::Matrix::Matrix(std::vector<double> const & arr,int row,int col)
    {
        int arrlen=arr.size();
        if(row<=0||col<=0||arrlen!=(row*col))//return if the input isnt right
        {
            	string ex="not a valid code";
		        throw invalid_argument(ex);
        }

        unsigned long row1=(unsigned long)(row);
        unsigned long col1=(unsigned long)(col);
       this->setcol(col);

       this->setrow(row);
       this->setarr(arr);
       vector<vector<double>> mat(row1,vector<double>(col1,0));
       for (size_t i = 0; i < row; i++)
       {
           for (size_t j = 0; j < col; j++)
           {
            mat[i][j]=arr[i*col1+j];
           }
           
       }
       this->setmatrix(mat); 
    }
    //return  the mult of matrix with double
    Matrix  Matrix::operator* (  double d) const
    {
        unsigned long cols=(unsigned long)(this->getcol());
                vector<double> arr=this->getarr();
               for (size_t i = 0; i < this->getrow(); i++)
               {
                   for (size_t j = 0; j < this->getcol(); j++)
                   {
                       arr[i*cols+j]*=d;                 }
                   
               }
               Matrix ret{arr,this->getrow(),this->getcol()};
               return ret;
    }

     Matrix  Matrix::operator*= (double d) //mult the matrix with value
    {
            *this=*this*d;
               return *this;
    }

        zich::Matrix zich::Matrix::operator+=(double d)
    {
        unsigned long cols=(unsigned long)(this->getcol());
                vector<double> arr=this->getarr();
                vector<vector<double>> mat=this->getmatrix();         
               for (size_t i = 0; i < this->getrow(); i++)
               {
                   for (size_t j = 0; j < this->getcol(); j++)
                   {
                       mat[i][j]+=d;
                       arr[i*cols+j]+=d;                 }
                   
               }
               this->setarr(arr);
                this->setmatrix(mat);
               return *this;
    }
            zich::Matrix zich::Matrix::operator-=(double d) 
    {
        unsigned long cols=(unsigned long)(this->getcol());
                vector<double> arr=this->getarr();
                vector<vector<double>> mat=this->getmatrix();         
               for (size_t i = 0; i < this->getrow(); i++)
               {
                   for (size_t j = 0; j < this->getcol(); j++)
                   {
                       mat[i][j]-=d;
                       arr[i*cols+j]-=d;                 }
                   
               }
               this->setarr(arr);
                this->setmatrix(mat);
               return *this;
    }




    zich::Matrix zich::Matrix::operator-(zich::Matrix const & mat) const 
    {
        if (this->getrow()!=mat._row||this->getcol()!=mat._cols)
        {
                string ex="not a valid code";
		        throw invalid_argument(ex);
        }
       vector<double> arr=this->getarr();
        unsigned long cols=(unsigned long)(this->getcol());

        for (size_t i = 0; i < mat._row; i++)
        {
            for (size_t j = 0; j < mat._cols; j++)
            {
              arr[i*cols+j]-=mat.mymatrix.matrix[i][j];
            }
            
        }
        Matrix ret{arr,mat._row,mat._cols};
        return ret;
        
        
    }
    zich::Matrix zich::Matrix::operator+(zich::Matrix const & mat)const
    {
                if (this->getrow()!=mat._row||this->getcol()!=mat._cols)
        {
                string ex="not a valid code";
		        throw invalid_argument(ex);
        }


        unsigned long cols=(unsigned long)(this->getcol());
        vector< double> arr=this->getarr();

        for (size_t i = 0; i < mat._row; i++)
        {
            for (size_t j = 0; j < mat._cols; j++)
            {
              arr[i*cols+j]+=mat.mymatrix.matrix[i][j];
            }
            
        }
        Matrix ret{arr,mat._row,mat._cols};
        return ret;
    }

    zich::Matrix zich::Matrix::operator*(const zich::Matrix  & mat) const
    {
        if (this->getcol()!=mat._row)
        {
                string ex="not a valid code";
		        throw invalid_argument(ex);
        }
        unsigned long row1=(unsigned long)(this->getrow());
        unsigned long col1=(unsigned long)(this->getcol());
        unsigned long col2=(unsigned long)(mat.getcol());

        vector<double>ret(row1*col2,0);
    
        for (size_t i = 0; i < row1; i++)
        {
            for (size_t j = 0; j < col2; j++)
            {
                for (size_t k = 0; k < col1; k++)
                {
                    ret[i*col2+j]+=this->mymatrix.matrix[i][k]*mat.mymatrix.matrix[k][j];
                } 
            } 
        }
        Matrix ret1(ret,this->getrow(),mat._cols);
        return ret1;
    }


    zich::Matrix zich::Matrix::operator+=(zich::Matrix const & mat)
    {
        *this=*this+mat;
        return *this;
    }

        zich::Matrix zich::Matrix::operator-=(zich::Matrix const & mat)
    {
        *this=*this-mat;
        return *this;
    }
           zich::Matrix zich::Matrix::operator*=(zich::Matrix const & mat)
    {
        *this=*this*mat;
        return *this;
    }


    

    bool zich::Matrix::operator==(zich::Matrix const & mat) const
    {
        if (this->getrow()!=mat._row||this->getcol()!=mat._cols)
        {
                string ex="not a valid code";
		        throw invalid_argument(ex);
        }

        return this->getarr()==mat._arr;
    }


    bool zich::Matrix::operator!=(zich::Matrix const & mat )const
    {
          if (this->getrow()!=mat._row||this->getcol()!=mat._cols)
        {
                string ex="not a valid code";
		        throw invalid_argument(ex);
        }
        return this->getarr()!=mat.getarr();
    }


    double zich::Matrix::sumMat(vector<double> x)//sum the values of the matrix
    {
        double ret=0;
        for (size_t i = 0; i < x.size(); i++)
        {
             ret+=x[i];
        }
        
        return ret;
    }

    bool zich::Matrix::operator>=(zich::Matrix const & mat) const
    {
                if (this->getrow()!=mat._row||this->getcol()!=mat._cols)
        {
                string ex="not a valid code";
		        throw invalid_argument(ex);
        }
        double s1=sumMat(this->getarr());
        double s2=sumMat(mat._arr);
        return s1>=s2;
    }

    bool zich::Matrix::operator<=(zich::Matrix const & mat) const
    {

        return !(*this>mat);
    }

    bool zich::Matrix::operator<(zich::Matrix const & mat)const
    {
        return !(*this>=mat);
    }
    bool  zich::Matrix::operator> (zich::Matrix const  &mat) const
    {
        if (this->getrow()!=mat._row||this->getcol()!=mat._cols)
        {
                string ex="not a valid code";
		        throw invalid_argument(ex);
        }
        double s1=sumMat(this->getarr());
        double s2=sumMat(mat._arr);
        return s1>s2;
    }
    zich::Matrix zich::Matrix::operator+()
    {
        vector<vector<double>> mat=this->getmatrix();
        vector<double> arr=this->getarr();
        for (size_t i = 0; i <arr.size(); i++)
        {
            arr[i]*=+1;
        }
        Matrix ret{arr,this->getrow(),this->getcol()};
        return ret;
    }
        zich::Matrix zich::Matrix::operator-()
    {
        vector<vector<double>> mat=this->getmatrix();
        vector<double> arr=this->getarr();
        for (size_t i = 0; i <arr.size(); i++)
        {
            arr[i]*=-1;
        }
        Matrix ret{arr,this->getrow(),this->getcol()};
        return ret;
    }
    
    //
    zich::Matrix zich::Matrix::operator--()
    {
        *this+=-1;
        return *this;
    }
        //

    zich::Matrix zich::Matrix::operator--(int)
    {
        Matrix ret=*this;
        *this+=-1;
        return ret;
    }
        //

    zich::Matrix zich::Matrix::operator++()
    {
        *this+=1;
        return *this;
    
    }
        //

    zich::Matrix zich::Matrix::operator++(int)
    {
      Matrix ret=*this;
        *this+=1;
        return ret;
    }
    zich::Matrix zich::operator*(int d,const zich::Matrix& mat){
        vector<double> arr=mat._arr;
        for (size_t i = 0; i < arr.size(); i++)
        {
            arr[i]*=d;
        }
        Matrix ret{arr,mat._row,mat._cols};
        return ret;
    }

std::ostream &zich::operator<<(std::ostream& stream, const zich::Matrix& x){
    for (size_t i = 0; i < x.getrow(); i++)
    {
        stream<<"[";
        for (size_t j = 0; j < x.getcol(); j++)
        {
            stream<<x.mymatrix.matrix[i][j];
            if(j<x.getcol()-1)
            {
                stream<<" ";
            }
        }
        if(i<x.getrow()-1){
        stream<<"]\n";
        }else{stream<<']';} 
    }

    
    return stream;
}
std::istream &zich::operator>>(std::istream & is,zich::Matrix & m)
{

    vector<double> v;
    string mat;
    char c=' ';
    unsigned long r=1;
    unsigned long col=1;
    bool first=true;
    bool in=false;
    int i=0;
    while (is)
    {
        c=is.get();
        if (c=='[')
        { if(in)
        {
            	string ex="not a valid code";
		        throw invalid_argument(ex);
        }
            in=true;
            i=1;
        }
        else if (c==',')
        {
            r++;
            c=is.get();
            if (c!=' ')
            {
                	string ex="not a valid code";
		        throw invalid_argument(ex);
            }
            
        }
        else if (in){
            if (first && c==' ')
            {
                col++;
            }
            else if (c==']')
            {
                first=false;
                in=false;
            }else if(!first)
            {
                if (c==' ')
                {
              
                
                i++;
                if (i>int(col))
                {
                    string ex="not1";
		            throw invalid_argument(ex);
                }
                }
                
            }
                mat+=c;
            }  
    }
    
    std::stringstream iss(mat);
    unsigned long count=0;
    double num=0;
    vector<double> arr(r*col,0);
    while (iss>>num)
    {
        arr[count++]=num;
    }
    try
    {
         Matrix m{arr,int(r),int(col)};
    }
    catch(const std::exception& e)
    {
       	string ex="cant creat Matrix";
		throw invalid_argument(ex);;
    }
    return is;
}
 