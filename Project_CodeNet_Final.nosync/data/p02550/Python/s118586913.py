N, X, M = map(int, input().split())
if X <= 1:
    print(X*N)
    exit()
check = [0]*(M+1)
check[X] += 1
A = X
last_count = 0
while True:
    A = (A**2)%M
    if check[A] != 0:
        last_count = sum(check)
        target_value = A
        break
    check[A] += 1
A2 = X
first_count = 0
while A2 != target_value:
    first_count += 1
    A2 = (A2**2)%M

roop_count = last_count-first_count

A3 = target_value
mass = A3
for i in range(roop_count-1):
    A3 = (A3**2)%M
    mass += A3
if roop_count == 0:
    print(N*X)
    exit()
if first_count != 0:
    ans = X
    A = X
    for i in range(min(N,first_count)-1):
        A = (A**2)%M
        ans += A
else:
    ans = 0
if N > first_count:
    ans += ((N-first_count)//roop_count)*mass
    A4 = target_value
    if (N-first_count)%roop_count >= 1:
        ans += A4
    for i in range(((N-first_count)%roop_count)-1):
        A4 = (A4**2)%M
        ans += A4
print(ans)