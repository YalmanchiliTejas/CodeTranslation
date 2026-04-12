    #include <iostream>
    #include <algorithm>
     
    struct edge
    {
    	int u, v, w;
    };
     
    struct point
    {
    	int firstCoordinate, secondCoordinate, position;
    };
     
    bool compare(const edge &x, const edge &y)
    {
    	return x.w < y.w;
    }
     
    bool compareByX(const point &x, const point &y)
    {
    	return x.firstCoordinate > y.firstCoordinate;
    }
     
    bool compareByY(const point &x, const point &y)
    {
    	return x.secondCoordinate > y.secondCoordinate;
    }
     
     
     
    int roots[200020], sums[200020], ans[200020] = { 0 }, maxSum = 0, position = 0;
     
    void initialize(int n)
    {
    	for (int i = 0; i < n; ++i)
    	{
    		roots[i] = i;
    		sums[i] = 1;
    	}
    }
     
    int root(int i)
    {
    	while (roots[i] != i)
    	{
    		roots[i] = roots[roots[i]];
    		i = roots[i];
    	}
    	
    	return i;
    }
     
    void makeUnion(edge edges[100010], int i)
    {
    	int rootOfA = root(edges[i].u), rootOfB = root(edges[i].v);
    	
    	if (sums[rootOfA] >= sums[rootOfB])
    	{
    		sums[rootOfA] += sums[rootOfB];
    		ans[rootOfA] += ans[rootOfB] + edges[i].w;
    		roots[rootOfB] = rootOfA;
    		
    		if (sums[rootOfA] > maxSum)
    		{
    			maxSum = sums[rootOfA];
    			position = i;
    		}
    	}
    	else
    	{
    		sums[rootOfB] += sums[rootOfA];
    		ans[rootOfB] += ans[rootOfA] + edges[i].w;
    		roots[rootOfA] = rootOfB;
    		
    		if (sums[rootOfB] > maxSum)
    		{
    			maxSum = sums[rootOfB];
    			position = i;
    		}
    	}
    }
     
    int main()
    {
    	int n, x, y;
    	std::cin >> n;
    	
    	edge edges[200020];
    	
    	point points[100010];
    	
    	for (int i = 0; i < n; ++i)
    	{
    		std::cin >> points[i].firstCoordinate >> points[i].secondCoordinate;
    		points[i].position = i;
    	}
    	
    	std::sort(points, points + n, compareByX);
    /*	for (int i = 0; i < n - 1; ++i)
    		std::cout << points[i].firstCoordinate << " " << points*/
    	for (int i = 0; i < n - 1; ++i)
    	{
    		edges[i].u = points[i + 1].position;
    		edges[i].v = points[i].position;
    		edges[i].w = points[i].firstCoordinate - points[i + 1].firstCoordinate;
    	}
    	
    	std::sort(points, points + n, compareByY);
    	for (int i = 0; i < n - 1; ++i)
    	{
    		edges[i + n - 1].u = points[i + 1].position;
    		edges[i + n - 1].v = points[i].position;
    		edges[i + n - 1].w = points[i].secondCoordinate - points[i + 1].secondCoordinate;
    	}
     
    	std::sort(edges, edges + (n + n) - 2, compare);
    	
    //	for (int i = 0; i < (n + n) - 2; ++i)
    //		std::cout << edges[i].u << " " << edges[i].v << " " << edges[i].w << "\n";
    	
    	initialize(n);
    	
    	for (int i = 0; i < (n + n) - 2; ++i)
    	{
    		if (root(edges[i].u) != root(edges[i].v))
    		{
    			makeUnion(edges, i);
    //			std::cout << edges[i].u << " " << edges[i].v << " " << edges[i].w << "\n"; 
    		}
    //		std::cout << edges[i].u << " " << edges[i].v << " " << edges[i].w << "\n";
    	}
     
    	std::cout << ans[root(position)];
    }