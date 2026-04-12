def main(istr, ostr):
    s = int(istr.readline().strip())
    if s >= 30:
        print('Yes', file=ostr)
    else:
        print('No', file=ostr)


if __name__ == "__main__":
    import sys

    main(sys.stdin, sys.stdout)
