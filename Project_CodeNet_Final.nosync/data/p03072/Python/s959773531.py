n=int(input())
h=list(map(int,input().split()))
print([max(h[:i+1])==h[i] for i in range(n)].count(1))