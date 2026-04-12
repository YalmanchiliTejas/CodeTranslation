from networkx import*
(n,_),*t=[[*map(int,t.split())]for t in open(0)]
print(sum(n==len(p)for i in range(n)for p in all_simple_paths(Graph(t),1,i+1)))