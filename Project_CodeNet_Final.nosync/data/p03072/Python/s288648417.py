# -*- coding: utf-8 -*-

from sys import stdin
    
def calc(ryokans):
    ans = 0
    _max = -1

    for x in ryokans:
        if x >= _max:
            ans += 1
            _max = x

    return ans

def main():
    n = stdin.readline().rstrip()
    ryokans = [int(x) for x in stdin.readline().rstrip().split()]
    ans = calc(ryokans)
    print(ans)
    
if __name__=='__main__':
    main()