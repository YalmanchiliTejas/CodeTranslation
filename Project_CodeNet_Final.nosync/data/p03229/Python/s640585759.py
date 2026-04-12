import sys
input = sys.stdin.readline

N = int(input())
A = [int(input()) for _ in range(N)]


A.sort()

def calc(A):
    ans = 0
    tmp1 = A[0]
    tmp2 = A[0]

    count = 1
    flag = True
    i = 1
    j = 1
    while True:
        if flag:
            if tmp1 > tmp2:
                tmp1, tmp2 = tmp2, tmp1
        else:
            if tmp1 < tmp2:
                tmp1, tmp2 = tmp2, tmp1


        if count == N:
            break
        if flag:
            ans += abs(tmp1 - A[-i])
            tmp1 = A[-i]
            i += 1
        else:
            ans += abs(tmp1 - A[j])
            tmp1 = A[j]
            j += 1

        count += 1

        if count == N:
            break
        if flag:
            ans += abs(tmp2 - A[-i])
            tmp2 = A[-i]
            i += 1
        else:
            ans += abs(tmp2 - A[j])
            tmp2 = A[j]
            j += 1
        
        count += 1

        flag = not flag
        # print ('A', ans)
    return ans

# print (i, j)
print (max(calc(A[::-1]), calc(A)))
