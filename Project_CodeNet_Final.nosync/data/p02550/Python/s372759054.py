N, X, M = map(int, input().split())

rec = []
s = set()
rec.append(X)
s.add(X)
r = X
idx = -1
idx1 = -1
for i in range(N+1):
    r = (r**2)%M
    if(r not in s):
        rec.append(r)
        s.add(r)
    else:
        rec.append(r)
        idx = i+1
        break
    
for i in range(len(rec)):
    if(rec[i] == rec[idx]):
        idx1 = i
        break

if(idx == -1 or idx1 == -1):
    print(sum(rec[:N]))
elif(idx1 != idx):       
    ans = sum(rec[:idx1])
    ans += sum(rec[idx1:idx])*((N-idx1)//(idx-idx1))+sum(rec[idx1:(idx1+(N-idx1)%(idx-idx1))])
    print(ans)
else:
    ans = sum(rec[:idx1])
    ans += rec[idx]*(N-idx1)
    print(ans)