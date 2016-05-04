//
//  main.cpp
//  Proyecto3A
//
//  Miguel Bazan A01281010
//  Ricardo Licea A01280892

#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main(int argc, const char * argv[])
{
    
    int iT = 0; // test cases
    int iN = 0; // numero de objetos
    int iArrP [1001]; // precio
    int iArrW [1001]; // peso
    int iG = 0;
    int iMatA [1001][1001];
    int iRes = 0;
    int iMaxWeight=0;
    
  
    cin >> iT;
    
    while (iT--)
    {
        
        for (int iR = 0; iR <= iN; iR++)
        {
            iMatA[iR][0] = 0;
        }
        for (int iA = 0; iA <= 1001; iA++)
        {
            iMatA[0][iA] = 0;
        }
        cin>> iN;
        
        for (int iA = 1; iA <= iN; iA++)
        {
            cin >> iArrP[iA] >> iArrW[iA];
        }
        
        for (int iA = 1; iA <= iN; iA++)
        {
            for (int iR = 0; iR <= 1001; iR++)
            {
                iMatA[iA][iR] = iMatA[iA - 1][iR];
                
                if (iArrW[iA] > iR)
                {
                    iMatA[iA][iR] = iMatA[iA-1][iR];
                }
                else
                {
                    iMatA[iA][iR] = max(iMatA[iA-1][iR],iArrP[iA] + iMatA[iA-1][iR - iArrW[iA]]);
                }
            }
        }
        
        cin >> iG;
        
        for (int iA = 0; iA < iG; iA++)
        {
            cin >>iMaxWeight;
            iRes += iMatA[iN][iMaxWeight];
            
        }

        cout<<iRes<<endl;
        iRes = 0;
    }
    return 0;
    
}