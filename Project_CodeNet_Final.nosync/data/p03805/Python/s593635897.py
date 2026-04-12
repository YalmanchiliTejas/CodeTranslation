from networkx import*
(n,_),*t=map(str.split,open(0))
n=int(n)
print(sum(n==len(p)for i in range(n)for p in all_simple_paths(Graph(t),'1',str(i+1))))