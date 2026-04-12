import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
 
def main():
    x = int(readline())
    if x >= 30:
        print('Yes')
    else:
        print('No')
if __name__ == '__main__':
    main()
