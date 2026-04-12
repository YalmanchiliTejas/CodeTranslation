N, X = map(int, input().split())
As = [1]
Ps = [1]
for i in range(N):
    As.append(As[i] * 2 + 3)
    Ps.append(Ps[i] * 2 + 1)

def f(n, x):
    if n == 0:
        return 0 if x <= 0 else 1

    med = (As[n] + 1) // 2
    if x < med:
        return f(n - 1, x - 1)
    elif x == med:
        return Ps[n - 1] + 1
    elif x > med:
        return Ps[n - 1] + 1 + f(n - 1, x - med)

answer = f(N, X)
print(answer)

# def make_burger(s, count):
#     # count += 1
#     # print(s)
#     if count == N:
#         return s
#     return make_burger('B' + s + 'P' + s + 'B', count + 1)

# print(make_burger('P', 0))