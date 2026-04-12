from collections import defaultdict
 
 
def main():
    s = input().replace(" ", "")
    print("YES" if int(s) % 4 == 0 else "NO")
 
 
if __name__ == '__main__':
    main()