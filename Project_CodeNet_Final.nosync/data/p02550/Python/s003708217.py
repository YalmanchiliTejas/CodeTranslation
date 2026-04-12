N, X, M = map(int,input().split())
ans = X
lst = [X]
check = [0] * M
check[X] += 1
A = X
flag = False
for i in range(N-1):
    A = A**2 % M
    if check[A] == 0:
        check[A] += 1
        lst.append(A)
        ans += A
    else:
        flag = True
        init = lst.index(A)
        last = i+1
        break
if flag:
    new_list = lst[init:]
    l = len(new_list)
    s = sum(new_list)
    num = N - last
    ans += s * (num//l)
    for i in range(num%l):
        ans += new_list[i]

print(ans)