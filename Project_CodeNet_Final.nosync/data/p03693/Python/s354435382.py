A = list(map(int, input().split()))
print('YES' if (A[1]*10+A[2])%4 ==0 else 'NO')