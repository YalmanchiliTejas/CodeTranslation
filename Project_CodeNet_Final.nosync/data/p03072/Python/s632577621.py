import sys

def solve(N, mounts):
    count = 0
    for i in xrange(N):
        max_h = max(mounts[0:i+1])
        if mounts[i] >= max_h:
            count += 1
    return count

if __name__ == '__main__':

    N = sys.stdin.readline().strip()
    mounts = map(int, sys.stdin.readline().strip().split(" "))
    ans = solve(int(N), mounts)
    print ans