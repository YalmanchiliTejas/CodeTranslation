N=int(input())
S=str(input())
K=int(input())
x=S[K-1]
res1=[i if i == x else "*" for i in S]
res2="".join(res1)
print(res2)