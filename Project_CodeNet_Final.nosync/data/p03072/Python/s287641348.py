N=int(input())
H=list(map(int,input().split()))
print(len([i for i in range(N) if H[i]>=max(H[:i+1])]))