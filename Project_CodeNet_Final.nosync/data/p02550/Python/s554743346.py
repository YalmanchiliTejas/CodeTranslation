import sys

N, X, M = map(int, input().split())

cnt = [0] * M
accu = [X]
cnt[X] = 1
for i in range(2,min(N+1, M+3)):
    s = (accu[-1] ** 2) % M
    if cnt[s] == 0:
        cnt[s] = i
        accu.append(s)
    else:
        c = i - cnt[s] 
        su = sum(accu[cnt[s]-1:])
        ans = sum(accu[:cnt[s]-1])
        N -= (cnt[s] - 1)
        n = N // c
        ans += n * su
        N %= c
        ans += sum(accu[cnt[s]-1:cnt[s]+ N -1])
        print(ans)
        sys.exit()

print(sum(accu))
    
    
    
