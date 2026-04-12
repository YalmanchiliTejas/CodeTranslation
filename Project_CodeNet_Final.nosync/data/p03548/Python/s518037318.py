X,Y,Z = map(int ,input().split())
ans = -1
use = Z
while(use <= X):
	use += Y+Z
	ans += 1
    
print(ans)


