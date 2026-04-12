def sim(n, a):
    ans = 0
    for i in range(n):
        div = a[i] / n
        ans += div
        for j in range(n):
            a[j] += div
            if i == j:
                a[j] -= div + div * n
    return ans, a

    

N = input()
A = map(int, raw_input().split())

final_ans = 0
ans, a = sim(N, A)
final_ans = ans
while True:
    ans, a = sim(N, a)
    if ans == 0:
        break
    else:
        final_ans += ans

print final_ans    