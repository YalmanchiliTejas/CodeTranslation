N,X = map(int,input().split())
alist = [2**(i+2)-3 for i in range(N+1)]
cntlist = [2**(i+1)-1 for i in range(N+1)]
cnt = 0
i = 0

while True:
    i += 1
    if X <= N-i+1:
        break
    elif alist[-i] - (N-i+1) <= X:
        cnt += cntlist[-i]
        break
    elif alist[-i]//2 +1 < X: # 左
        cnt += cntlist[-i]//2 +1
        X -= alist[-i]//2 +1
    elif X == alist[-i]//2 +1: # 真ん中
        cnt += cntlist[-i]//2 + 1
        break
    elif X < alist[-i]//2 +1: # 右
        X -= 1

print(cnt)