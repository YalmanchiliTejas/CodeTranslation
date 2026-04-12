N=int(input())
H=list(map(int,input().split()))
print(sum(max(H[:i]+[0])<=H[i] for i in range(N)))