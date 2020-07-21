#include<bits/stdc++.h>
#define FOR(i,a,b) for(i=a;i<b;i++)
#define flash ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;
int a[9][9];    //Sudoku Grid

int checkrow(int i,int val)
{
    int k;
    FOR(k,0,9)
        if(a[i][k]==val)
            return 0;
    return 1;
}
int checkcol(int j,int val)
{
    int k;
    FOR(k,0,9)
        if(a[k][j]==val)
            return 0;
    return 1;
}
int checksq(int i,int j,int val)
{
    //Finding which square (i,j) lies in
    int n,k;
    int rw = ceil(((float)(i+1))/3);
    int cl = ceil(((float)(j+1))/3);
    FOR(k,3*(rw-1),((rw-1)*3+3))
        FOR(n,3*(cl-1),((cl-1)*3+3))
            if(a[k][n]==val)
                return 0;
    return 1;
}
int main()
{
    flash;
    int i,j,val,count;
    bool flag;
    start:
    count=0;
    flag=1;
    cout<<"----------::  SUDOKU SOLVER USING C++  ::-----------"<<endl;
    cout<<endl<<"Enter Sudoku Matrix with 0 in blanks"<<endl;
    FOR(i,0,9)
        FOR(j,0,9){
            cin>>a[i][j];
            if(a[i][j]==0)
                count++;    //count of number of blanks
        }
    // FOR(i,0,9){FOR(j,0,9)cout<<a[i][j]<<" ";cout<<endl;}
    while(count>0&&flag==1)
    {
        flag=0;
        FOR(i,0,9)
        {
            FOR(j,0,9)
            {
                if(a[i][j]!=0)  // If cell is not empty then continue to next 
                continue;   
                int temp = 0;
                FOR(val,1,10)
                {
                    if(checkrow(i,val)) //checks if val aready occurs in ith row
                        if(checkcol(j,val)) //checks if val aready occurs in jth col
                            if(checksq(i,j,val))    //checks if val aready occurs in its square
                            {
                                if(temp==0) 
                                    temp = val; //val is unique and can be assigned
                                else
                                {
                                    temp=0;
                                    break;
                                }
                            }
                }
                if(temp){
                    count--;
                    a[i][j]=temp;
                    flag=1;
                }
            }
        }
    }
    if(flag==0)
        cout<<endl<<"THIS SUDOKO IS UNSOLVABLE !!"<<endl;
    else if(count==0)
    {
        cout<<endl<<"    SOLVED IT !"<<endl<<endl<<"-:::SOLUTION:::-"<<endl<<endl;
        FOR(i,0,9)
        {
            FOR(j,0,9)
                cout<<a[i][j]<<" ";
            cout<<endl;
        }
    }
    cout<<endl<<"Have another Sudoku to solve ?? (Y/N)"<<endl;
    char c;
    cin>>c;
    if(c=='Y'||c=='y')
        goto start;
    cout<<endl<<"TERMINATING..."<<endl;
    return 0;
}
