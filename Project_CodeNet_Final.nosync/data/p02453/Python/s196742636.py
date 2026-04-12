# http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_6_C&lang=jp
#  Lower Bound : python3
#  2018.11.26 yonezawa

import sys
input = sys.stdin.readline

def LowerBound(d,l):
    max = len(l) -1
    min = 0
    mid = max // 2
    while True:
        if (l[mid] > d ):
            max = mid
        elif (l[mid] == d ):
            while l[mid] == d and mid >= 0:
                mid -= 1
            return mid + 1
        else:
            min = mid
        mid =  (max + min ) // 2 

        if ( mid == max or mid == min ):
            if ( l[mid] == d or l[max] == d):
                while l[mid] == d and mid >= 0:
                    mid -= 1
                return mid+1
            if ( l[max] < d ):
                return len(l)
            if ( l[mid] > d):
                return min
            return max
def main():
    nl = int(input())
    l = list(map(int,input().split()))

    for i in range(int(input())):
        n = int(input())
        result = LowerBound(n,l)
        print (result)


if __name__ == '__main__':
    main()
