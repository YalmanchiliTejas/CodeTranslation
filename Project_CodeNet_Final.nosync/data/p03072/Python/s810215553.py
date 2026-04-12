N=int(input())
H=list(map(int, input().split()))
s=[i for i in range(1,N) if H[i]>=max(H[:i])]
print(len(s)+1)