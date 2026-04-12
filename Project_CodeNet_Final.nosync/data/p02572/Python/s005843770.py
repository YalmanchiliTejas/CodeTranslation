import sys
input = sys.stdin.readline

def main():
    n = int( input() )
    A = list( map( int , input().split() ) )
    A_sum = sum(A)
    A_sum -= A[0]
    ans = 0

    for i in range( n - 1 ) :
        a_i = A[i]
        ans += ( (A_sum * a_i) % (10 ** 9 + 7 ) )
        A_sum -= A[ i + 1 ]
        ans %= ( 10 ** 9 + 7 )

    print(ans)



main()