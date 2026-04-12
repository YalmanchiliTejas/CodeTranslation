X,Y,Z = map(int, input().split())
ans = X//(Y+Z) - 1
if ans*(Y+Z)+(Y+Z+Z) <= X: ans += 1
print(ans)