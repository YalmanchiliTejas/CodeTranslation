import re

def main():
    H, W = map(int, raw_input().split())
    prev_end = 0
    HASH_RE = re.compile(r"#+")
    for i in range(H):
        A = raw_input()
        if HASH_RE.search(A, endpos=prev_end-1) is not None:
            print "Impossible"
            return 0

        m = HASH_RE.search(A, pos=prev_end-1)
        if m is None:
            print "Impossible"
            return 0

        if HASH_RE.search(A, pos=m.end()):
            print "Impossible"
            return 0

        prev_end = m.end()

    print "Possible"

if __name__ == "__main__":
    main()
