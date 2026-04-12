import sys
 
def main():
    x = int(sys.stdin.readline().strip())
    
    if x == 7 or x == 5 or x == 3:
        print("YES")
    else:
        print("NO")
 
if __name__ == "__main__":
    main()