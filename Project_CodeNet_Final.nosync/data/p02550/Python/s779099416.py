# -*- coding: utf-8 -*-
# map(int, input().split())
N,X,M = map(int, input().split())

first_A = [X]
mod_M = [False for i in range(M+1)]
mod_M[0] = True
mod_M[1] = True

is_break = False
for i in range(min(N-1,M+1)):
    A_n1 = pow(first_A[-1],2)%M
    if mod_M[A_n1]:
        is_break = True
        last_num = A_n1
        break
    else:
        first_A.append(A_n1)
        mod_M[A_n1] = True

if is_break:
    if last_num == 0:
        print(sum(first_A))
    elif last_num == 1:
        nokori = N-len(first_A)
        print(sum(first_A)+nokori)
    else: # roop
        loop_idx = first_A.index(last_num)
        first_A, second_A = first_A[:loop_idx], first_A[loop_idx:]
        roop = int((N-len(first_A))/len(second_A))
        nokori_kaisuu = (N-len(first_A)) - (roop*len(second_A))
        if nokori_kaisuu == 0:
            print(sum(first_A)+(sum(second_A)*roop))
        else:
            print(sum(first_A)+(sum(second_A)*roop)+sum(second_A[:nokori_kaisuu]))
else:
    print(sum(first_A))