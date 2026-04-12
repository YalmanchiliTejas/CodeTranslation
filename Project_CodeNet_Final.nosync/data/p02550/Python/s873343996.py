n, x, m = map(int, input().split())
A = [x]
checkA = {x}
ans = x

for i in range(1,n):
    buf = A[i-1]*A[i-1] % m
    if buf in checkA:
        idx = A.index(buf)
        back = len(A) - idx
        nokori = n-len(A)
        sumKurikaeshi = sum(A[idx:])
        ans += int(nokori/back)*sumKurikaeshi
        last = nokori%back
        ans += sum(A[idx:idx+last])
        break
    else:
        A.append(buf)
        checkA.add(buf)
        ans += buf

print(ans)