#ifndef INTERPLIB_H
#define INTERPLIB_H value

#include <fstream>
#include <string>
#include <vector>
#include "boost/numeric/ublas/matrix.hpp"
#include "boost/numeric/ublas/vector.hpp"
#include "boost/numeric/ublas/lu.hpp"
#include "boost/filesystem.hpp"

namespace ublas=boost::numeric::ublas;
namespace fs=boost::filesystem;

//right now this just takes the path to a filename in the constructor and sets up an instance
//of the interpolator class where all of the necessary matrices/vectors are built.
//
//After the object is built, its interpAt member function can be run any number of times without having to redo all the time-intensive math.
//
//
//ToDo:
//-overload the constructor so that it can take *x, *y, and n (double pointer arrays as straight form the output of Dr.Clark's file reader

class SplineInterp
{

    private:
        //this is the length of the input file
        int n;

        //These are the vectors that the data will be stored int
        ublas::vector<double> X;
        ublas::vector<double> Y;

        //these are the "end goal" from the interpolation method. When these coefficients are determined,
        //they can be used to generate the splines that the interpolations are calculated at
        ublas::vector<double> a;
        ublas::vector<double> b;

        void initCoefficients();

    protected:

    public:
        SplineInterp(double targetValue);
        SplineInterp();
        ~SplineInterp();

        double interpAt( double targetValue );
        double operator()( double interpValue );
        double operator[]( double interpValue );

        void setData( size_t n, double *x, double *y );
        void setData( std::vector<double> x, std::vector<double> y );

};

#endif
