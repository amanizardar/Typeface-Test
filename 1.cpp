#include <bits/stdc++.h>
using namespace std;
bool isValid(vector<vector<int>>&screen, int x, int y){
    int m=screen.size();
    int n=screen[0].size();
	if(x<0||x>=m||y<0||y>=n||screen[x][y]==0||screen[x][y]==-1)
		return false;
	return true;
}
// FloodFill function
vector<int> floodFill(vector<vector<int>> &screen, int x, int y){
    int min_x,max_x,min_y,max_y;
    int m=screen.size();
    int n=screen[0].size();
	vector<pair<int,int>> queue;
	pair<int,int> p(x,y);
	min_x=x;
	max_x=x;
	min_y=y;
	max_y=y;
	queue.push_back(p);
	// mark the pixel as visited
	screen[x][y] = -1;
	while(queue.size() > 0)
	{
		// Dequeue the front node
		pair<int,int> currPixel = queue[queue.size() - 1];
		queue.pop_back();
		int posX = currPixel.first;
		int posY = currPixel.second;
		// Check if the adjacent pixels are white
		if(isValid(screen, posX + 1, posY))
		{
			// Mark this position
			screen[posX + 1][posY] = -1;
			p.first = posX + 1;
			p.second = posY;
			min_x=min(min_x,p.first);
			max_x=max(max_x,p.first);
			min_y=min(min_y,p.second);
			max_y=max(max_y,p.second);
			queue.push_back(p);
		}
		if(isValid(screen, posX-1, posY))
		{
			screen[posX-1][posY]= -1;
			p.first = posX-1;
			p.second = posY;
			min_x=min(min_x,p.first);
			max_x=max(max_x,p.first);
			min_y=min(min_y,p.second);
			max_y=max(max_y,p.second);
			queue.push_back(p);
		}
		if(isValid(screen, posX, posY + 1))
		{
			screen[posX][posY + 1]= -1;
			p.first = posX;
			p.second = posY + 1;
			min_x=min(min_x,p.first);
			max_x=max(max_x,p.first);
			min_y=min(min_y,p.second);
			max_y=max(max_y,p.second);
			queue.push_back(p);
		}
		if(isValid(screen, posX, posY-1))
		{
			screen[posX][posY-1]= -1;
			p.first = posX;
			p.second = posY-1;
			min_x=min(min_x,p.first);
			max_x=max(max_x,p.first);
			min_y=min(min_y,p.second);
			max_y=max(max_y,p.second);
			queue.push_back(p);
		}
	}
	return {(min_x+max_x)/2.0,(min_y+max_y)/2.0,max_y-min_y+1,max_x-min_x+1};
}
	
int main()
{

vector<vector<int>> screen={
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 1, 0, 0, 0, 0, 0},
	{0, 1, 1, 1, 0, 0, 0, 0},
	{0, 1, 1, 1, 0, 0, 0, 0},
	{0, 1, 1, 1, 0, 0, 0, 0},
	{0, 0, 1, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0}};
// 	uncomment below code to take custom input and comment above declaration to avoid redeclaration error 
	// Number of Row
	int m = 8;
	// 	cin>>m;
	// Number of Column
	int n = 8;
// 	cin>>n;
    // int temp;
    // vector<vector<int>>screen(m,vector<int>(n,0));
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         cin>>temp;
    //         screen[i][j]=temp;
    //     }
    // }
    vector<vector<int>>ans;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(screen[i][j]==1){
                vector<int>temp=floodFill(screen,i,j); 
                ans.push_back(temp);
            }
        }
    }
    cout<<"[";
    for(auto a:ans){
        cout<<"["<<a[0]<<", "<<a[1]<<", "<<a[2]<<", "<<a[3]<<"] ";
    }
    // centerX and centery is calculated based on 0 based indexing
    cout<<"]"<<endl;
	return 0;
}