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


TModel* Model = new TArenstorfModel2();

TIntegrator* Integrator = new TDormandPrinceIntegrator();
	Integrator->setPrecision(1e-16);
	printf ("1");
	Integrator->Run( Model );
	printf ("2");
	TMatrix Result = Model->getResult();

	TVector Res = Model->getInitialConditions();
	
	
    printf ("\nTVector Res\n");
	for (int z=0; z<4; z++)
	{
		printf("%f   ", Res[z]);
	}
	
	
	//printf("Model = %5.2f   ", Model->getInitialConditions());
	
	printf("\nCount string Matrix_x = %i", Result.rowCount());
	printf("\nCount column Matrix_x = %i", Result.colCount());
	

    printf("\nResult: \n");
	for (int i=0; i<Result.rowCount(); i++)
	{
		for (int j=0; j<Result.colCount(); j++)
		{
            printf("%5.3f;", Result(i,j));
		}
		printf("\n");
	}
	

	delete Integrator;
	delete Model;
	return 0;
}
