N, X, M = map(int, input().split())

A = X
i = 1
sigma = X
A_list = [None, X]
A_sigma = [None, X]
A_index = {X: 1}
cycled = False
while i < N:
    A = A*A % M
    i += 1
    sigma += A

    if cycled: continue

    A_list.append(A)
    A_sigma.append(sigma)
    if A not in A_index:
        A_index[A] = i
    else:
        cycle_len = i - A_index[A]
        cycles = (N-i) // cycle_len
        sigma += (sigma - A_sigma[A_index[A]]) * cycles
        i += cycles * cycle_len
        cycled = True

print(sigma)
