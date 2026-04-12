N = int(input())
S = input()
def f(n):
    if n == 'S':
        return 'W'
    if n == 'W':
        return 'S'
A = ['S','S']
fa = 1
B = ['S','W']
fb = 1
C = ['W','W']
fc = 1
D = ['W','S']
fd = 1
for i in range(1,N-1):
    x = S[i]
    if x == 'o':
        if A[i] == 'S':
            A.append(A[i-1])
        else:
            A.append(f(A[i-1]))
        if B[i] == 'S':
            B.append(B[i-1])
        else:
            B.append(f(B[i-1]))
        if C[i] == 'S':
            C.append(C[i-1])
        else:
            C.append(f(C[i-1]))
        if D[i] == 'S':
            D.append(D[i-1])
        else:
            D.append(f(D[i-1]))
    else:
        if A[i] == 'S':
            A.append(f(A[i-1]))
        else:
            A.append(A[i-1])
        if B[i] == 'S':
            B.append(f(B[i-1]))
        else:
            B.append(B[i-1])
        if C[i] == 'S':
            C.append(f(C[i-1]))
        else:
            C.append(C[i-1])
        if D[i] == 'S':
            D.append(f(D[i-1]))
        else:
            D.append(D[i-1])
if S[0] == 'o':
    if A[0] == 'S':
        if A[1] != A[-1]:
            fa = 0
    else:
        if A[1] == A[-1]:
            fa = 0
else:
    if A[0] == 'S':
        if A[1] == A[-1]:
            fa = 0
    else:
        if A[1] != A[-1]:
            fa = 0
if S[-1] == 'o':
    if A[-1] == 'S':
        if A[-2] != A[0]:
            fa = 0
    else:
        if A[-2] == A[0]:
            fa = 0
else:
    if A[-1] == 'S':
        if A[-2] == A[0]:
            fa = 0
    else:
        if A[-2] != A[0]:
            fa = 0
if fa == 1:
    x = A[0]
    for i in range(1,N):
        x += A[i]
    print(x)
    quit()
if S[0] == 'o':
    if B[0] == 'S':
        if B[1] != B[-1]:
            fb = 0
    else:
        if B[1] == B[-1]:
            fb = 0
else:
    if B[0] == 'S':
        if B[1] == B[-1]:
            fb = 0
    else:
        if B[1] != B[-1]:
            fb = 0
if S[-1] == 'o':
    if B[-1] == 'S':
        if B[-2] != B[0]:
            fb = 0
    else:
        if B[-2] == B[0]:
            fb = 0
else:
    if B[-1] == 'S':
        if B[-2] == B[0]:
            fb = 0
    else:
        if B[-2] != B[0]:
            fb = 0
if fb == 1:
    x = B[0]
    for i in range(1,N):
        x += B[i]
    print(x)
    quit()
if S[0] == 'o':
    if C[0] == 'S':
        if C[1] != C[-1]:
            fc = 0
    else:
        if C[1] == C[-1]:
            fc = 0
else:
    if C[0] == 'S':
        if C[1] == C[-1]:
            fc = 0
    else:
        if C[1] != C[-1]:
            fc = 0
if S[-1] == 'o':
    if C[-1] == 'S':
        if C[-2] != C[0]:
            fc = 0
    else:
        if C[-2] == C[0]:
            fc = 0
else:
    if C[-1] == 'S':
        if C[-2] == C[0]:
            fc = 0
    else:
        if C[-2] != C[0]:
            fc = 0
if fc == 1:
    x = C[0]
    for i in range(1,N):
        x += C[i]
    print(x)
    quit()
if S[0] == 'o':
    if D[0] == 'S':
        if D[1] != D[-1]:
            fd = 0
    else:
        if D[1] == D[-1]:
            fd = 0
else:
    if D[0] == 'S':
        if D[1] == D[-1]:
            fd = 0
    else:
        if D[1] != D[-1]:
            fd = 0
if S[-1] == 'o':
    if D[-1] == 'S':
        if D[-2] != D[0]:
            fd = 0
    else:
        if D[-2] == D[0]:
            fd = 0
else:
    if D[-1] == 'S':
        if D[-2] == D[0]:
            fd = 0
    else:
        if D[-2] != D[0]:
            fd = 0
if fd == 1:
    x = D[0]
    for i in range(1,N):
        x += D[i]
    print(x)
    quit()
if fa + fb + fc + fd == 0:
    print(-1)