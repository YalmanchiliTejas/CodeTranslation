
def main():
    N, X, M = map(int, input().split())
    Set = {X}
    A = [X]
    for i in range(1,M+1):
        nextA = A[i-1]**2 % M
        if nextA in Set:
            loop = A[A.index(nextA):]
            break
        else:
            Set.add(nextA)
            A.append(nextA)

    lenloop = len(loop)
    x, y = divmod(N-len(A), lenloop)
    ans = sum(A) + x*sum(loop) + sum(loop[0:y])
    print(ans)

main()
