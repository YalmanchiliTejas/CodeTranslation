n, x = map(int, input().split())
ans = 0
 
hambargers = [1]
patties = [1]
 
for i in range(1, n+1):
    num = hambargers[i-1] * 2 + 3
    patty_num = patties[i-1] * 2 + 1
    hambargers.append(num)
    patties.append(patty_num)
 
def cal(N, X):
    if N == 0:
        return 0 if X <= 0 else 1
    elif X <= 1 + hambargers[N-1]:
        return cal(N-1, X-1)
    else:
        return patties[N-1] + 1 + cal(N-1, X-2-hambargers[N-1])
 
print(cal(n, x))