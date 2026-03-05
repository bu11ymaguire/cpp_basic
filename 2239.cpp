#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> sdouku(10,vector<int>(10,0)); //1 - base 스도쿠
vector<pair<int,int>> rest; //

bool check(int x, int y, int val)
{
    for(int Y=1;Y<=9;Y++)
    {
        if(Y==y)continue;
        if(sdouku[x][Y]==val) return false;
    }

    for(int X=1;X<=9;X++){
        if(X==x)continue;
        if(sdouku[X][y]==val) return false;
    }

    int x_s = ((x-1)/3) * 3 + 1;
    int y_s = ((y-1)/3) * 3 + 1;

    for(int X=x_s; X<=x_s+2;X++)
    {
        for(int Y=y_s;Y<=y_s+2;Y++)
        {
            if(X==x&&Y==y)continue;
            if(sdouku[X][Y]==val) return false;
        }
        
    }

    return true;
    
    //가로축 검증 : 문제 없으면 통과!
    //세로축 검증 : 문제 없으면 통과!
    /*
    int x = rest[idx].first;
    int y = rest[idx].second;

    int x_s = ((x - 1) / 3) * 3 + 1;
    int y_s = ((y - 1) / 3) * 3 + 1;

    for(int Y = y_s; Y<=y_s+2; Y++){
      for(int X = x_x; X<=x_s+2; X++){
        if(x==X && y == Y) continue;
        문제 없으면 통과!
      }
    }
    */
}

void DFS(int idx)
{
    if (idx == rest.size())
    {
        for(int j = 1; j <=9; j++)
        {
            for(int i =1; i <=9; i++)
            {
                cout << sdouku[j][i];
            }
            cout << '\n';
        }
        exit(0);
    }

    int x = rest[idx].first;
    int y = rest[idx].second;

    for(int val = 1;  val <=  9; val++)
    {
        if(check(x,y,val))
        {
            sdouku[x][y] = val;
            DFS(idx+1);
            sdouku[x][y] = 0;
        }
    }
    
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i = 1; i <=9; i++)
    {
        string input;
        cin >> input;
        for(int j =0; j < 9; j++)
        {
            sdouku[i][j+1] = input[j] - '0';
            if(input[j]=='0'){
                rest.push_back({i,j+1});
            } 
        }
    }

    DFS(0);

    return 0;
}