mod = 1000000007
n = int(input())
A = [int(x) for x in input().split()]
cum = [0]
for a in A:
    cum.append((cum[-1] + a)%mod)

# sum(sum(A[i]*A[j] for j in range(i+1, n)) for i in range(n))%mod =
print(sum(A[i]*(cum[n] - cum[i+1])%mod for i in range(n))%mod)
