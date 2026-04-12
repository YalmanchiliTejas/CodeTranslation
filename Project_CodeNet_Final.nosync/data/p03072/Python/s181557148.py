N = int(input())
A= list(map(int,input().split()))
output=0

for i in range(N):
        hoge = 0
        for k in range(i):
                if A[k] <= A[i]:
                        hoge += 1
                else:
                        break
        if hoge == i:
                output += 1

print(output)