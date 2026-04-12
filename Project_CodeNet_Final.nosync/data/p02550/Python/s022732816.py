N, X, M = map(int, input().split())

#A = [ i**2 % M for i in range(M) ]
A = []
B = {}
a = X
i_repeat = 0
for i in range(N):
    if a in B.keys():
        i_repeat = B[a]
        break
    A.append(a)
    B.update({ a : i })
    a = a**2 % M
    i += 1

repeat_size = i - i_repeat
repeat_interval = N - i_repeat

num_repeats = repeat_interval // repeat_size
num_red = repeat_interval % repeat_size


res = sum(A[:i_repeat])
res += sum(A[i_repeat:i]) * num_repeats
res += sum(A[i_repeat:i_repeat+num_red])

print(res)

