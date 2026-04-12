n = int(input())
Max = 0
ans = 0
for i in map(int, input().split()):
    if i >= Max:
        Max = i
        ans += 1

print (ans)
