#pragma once//---------------------------------------------------------------------------



#include "model.h"

//---------------------------------------------------------------------------
// Задача Аренсторфа (начальные условия 1)

class TArenstorfModel  : public TModel
{
    protected:
        static const long double m;
		long double D1, D2;
    public:
        TArenstorfModel(  );
		void getRight( const TVector& X, long double t, TVector& Y );
};

//const long double TArenstorfModel::m  = 0.012277471;

//---------------------------------------------------------------------------
// Задача Аренсторфа (начальные условия 2)

class TArenstorfModel2 : public TArenstorfModel
{
    public:
        TArenstorfModel2(  );
};
//---------------------------------------------------------------------------
