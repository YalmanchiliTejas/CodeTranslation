from sys import stdin

def main():
    n = int(input())
    A = [int(x) for x in stdin.readline().rstrip().split()]

    m = 10 ** 9 + 7
    s = 0
    b_sum = sum(A)
    for i in range(len(A)-1):
        b_sum = b_sum -A[i]
        rest = b_sum % m
        ans = A[i] * rest % m
        s += ans

    s = s % m
    print(s)
    
if __name__ == "__main__":
    main()