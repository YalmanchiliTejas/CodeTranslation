def create_sum(N):
    list_align = [2 for _ in range(N)]
    for i in range(N):
        if i % 2 == 0:
            list_align[i] *= -1
    list_align[0] //= 2
    list_align[N-1] //= 2
    list_align.sort()
    return list_align

def solve(N, Array):
    sum1 = 0
    sum2 = 0
    arr = create_sum(N)
    for i in range(N):
        sum1 += arr[i] * Array[i]
        sum2 += arr[i] * Array[N-1-i]
    print(max(abs(sum1), abs(sum2)))
    
if __name__ == "__main__":
    N = int(input())
    A = [int(input()) for _ in range(N)]
    A.sort()
    solve(N, A)