A, B, C, X, Y = map(int,input().split())
Sum=[0 for i in range(max(X,Y)+1)]


for AB in range(0, 2*max(X,Y)+1,2):
    Sum[AB//2]=max((X-AB//2),0)*A+max((Y-AB//2),0)*B+AB*C

print(min(Sum))