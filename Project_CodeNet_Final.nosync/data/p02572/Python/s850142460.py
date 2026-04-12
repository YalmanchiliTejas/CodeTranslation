Q = 10**9+7
def main():
    N = int( input())
    A = list( map( int, input().split()))
    S = sum(A)%Q
    T = sum( [a*a for a in A])%Q
    print((S*S%Q-T)*pow(2,Q-2,Q)%Q)
if __name__ == '__main__':
    main()