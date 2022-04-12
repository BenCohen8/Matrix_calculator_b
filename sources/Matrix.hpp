#include <iostream>
#include <vector>
using namespace std;
namespace zich{
  

    class Matrix
    {
        struct myMatrix
        {
            std::vector<std::vector<double>> matrix;

        };
        
        private:
        std::vector<double> _arr;
        int _row=0;
        int _cols=0;
        myMatrix mymatrix;

        public:

        Matrix();
        Matrix(const std::vector<double>&  arr,int ,int );
        friend  Matrix operator*(int,const Matrix& m);

        //math operators with double
        Matrix operator*= (double) ;
        Matrix operator+=(double);
        Matrix operator-=(double);

        Matrix operator* (double) const;
        Matrix operator+(double);
        Matrix operator-(double);

        //math operators with another matrix
        Matrix operator+=(const Matrix&);
        Matrix operator*=(const Matrix &);
        Matrix operator-=(const Matrix&);

        Matrix operator-(const Matrix& m ) const;
        Matrix operator*(const Matrix& m) const;
        Matrix operator+(const Matrix& m) const;

        Matrix operator-();
        Matrix operator+();

        Matrix operator--();//prefix --
        Matrix operator--(int);//suffix --
        Matrix operator++();//prefix ==
        Matrix operator++(int);//suffix ++
        //compare operators
        bool operator==(const Matrix&m) const;
        //friend bool operator==(const Matrix&mat1,const Matrix&mat2) ;

        bool operator>=(const  Matrix&m)const;
        bool  operator>  (const Matrix&m) const;
        bool operator<(const Matrix&m)const;
        bool operator<=(const Matrix&m) const;
        bool operator!=(const Matrix&m)const;


        static double sumMat(vector<double> x);

        friend std::ostream & operator<< (std::ostream &stream, const  Matrix &matrix );
        friend std::istream &  operator>>(std::istream &is,Matrix  & m );
        //getters and setters
        void setrow(int row){this->_row=row;}
        void setcol(int col){this->_cols=col;}
        void setarr(std::vector<double> arr){this->_arr=arr;}
        void setmatrix(std::vector<std::vector<double>> mat){this->mymatrix.matrix=mat;}
         int getrow() const{return this->_row;}
        const int &getcol()const{return this->_cols;}
        std::vector<double> getarr()const{return this->_arr;}
        std::vector<std::vector<double>> getmatrix(){return this->mymatrix.matrix;}






    };
    
}