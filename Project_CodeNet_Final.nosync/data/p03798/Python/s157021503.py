n = int(input())
s = input()

ok = 0

for ii in [[0,0], [0,1], [1,0], [1,1]]:
    A = [ii[0], ii[1]]
    # print(A)
    for i in range(1, n-1):
        A.append(int((A[-1] == 1) ^ (A[-2] == 1) ^ (s[i] == "x")))
    # print(A)
    if (A[-2] == 1) ^ (A[-1] == 1) ^ (A[0] == 1) ^ (s[-1] == "o") and \
        (A[-1] == 1) ^ (A[0] == 1) ^ (A[1] == 1) ^ (s[0] == "o"):
        ok = 1
        break

if ok == 0:
    print(-1)
else:
    ans = []
    for i in range(n):
        if A[i] == 0:
            ans.append("S")
        else:
            ans.append("W")
    print("".join(ans))