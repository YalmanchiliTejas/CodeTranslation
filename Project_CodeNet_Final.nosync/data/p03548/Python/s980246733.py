X, Y, Z = map(int, input().split())

sum = 0

for i in range(1,X):
    if sum > X:
        ans = i-2
        break
    if sum == X:
        ans = i-1
        break
    else:
        sum = Y*i+Z*(i+1)

print(ans)
