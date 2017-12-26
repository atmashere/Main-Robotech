/* Standard library	*/


#include <tchar.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include "array.h"

#define max(a, b) ( ( (a) > (b) ) ? (a) : (b) )
#define min(a, b) ( ( (a) < (b) ) ? (a) : (b) )


#include "integrator.h"
#include "custom.h"


//#include "array.h"

int main()
{
	
	//printf ("max of 10, 20 is %d\n", max (10, 20));
	//printf ("min of 10, 20 is %d\n", min (10, 20));

TModel* Model = new TArenstorfModel();

//Model->t0 = 0; //62208000  (2457833.5 - 2457754.5)*86400
//Model->setSamplingFrequency( 1e-2 ); //Model->getT1();


TIntegrator* Integrator = new TDormandPrinceIntegrator();
	Integrator->setPrecision(1e-16);
	printf ("1");
	Integrator->Run( Model );
	printf ("2");
	TMatrix Result = Model->getResult();

	TVector Res = Model->getInitialConditions();
	
	
	
	//TVector getRight = Model->getRight();
	//printf("%f   ", Model->m);
	
	
	
	
	
	
	printf ("\nTVector Res\n");
	for (int z=0; z<4; z++)
	{
		printf("%f   ", Res[z]);
	}
	
	
	//printf("Model = %5.2f   ", Model->getInitialConditions());
	
	printf("\nCount string Matrix_x = %i", Result.rowCount());
	printf("\nCount column Matrix_x = %i", Result.colCount());
	

	printf("\nResult");
	for (int i=0; i<Result.rowCount(); i++)
	{
		for (int j=0; j<Result.colCount(); j++)
		{
			printf("%5.2f   ", Result(i,j));
		}
		printf("\n");
	}
	

	delete Integrator;
	delete Model;


    //TArenstorfModel* modN1;

    //TArenstorfModel* Model1;
    //Result = Model2->getResult();
	
	//Model1.t0 = 0;
	//Model1 = new TArensorfModel(0, 20, 0.1);
	
	/*
	TIntegrator* Integrator;
	Integrator = new TDormandPrinceIntegrator();
	Integrator->setPrecision(1e-16);
	
	Integrator->Run( Model1 );
	TMatrix Result = Model1->getResult();
	*/
	//TModel* Model2 = new TArensorfModel2(0, 20, 0.1);
	
	
	
	//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX...
	
	//Integrator->Run( Model2 );
	//Result = Model2->getResult();
	//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX..
	
	//delete Integrator;
	//delete Model1;
	//delete Model2;
    //printf("end");
	return 0;
}
