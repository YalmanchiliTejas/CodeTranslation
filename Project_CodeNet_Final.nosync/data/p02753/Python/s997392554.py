#

import sys
input=sys.stdin.readline

def main():
    S=input()
    if "BA" in S or "AB" in S:
        print("Yes")
    else:
        print("No")
    
    
    
if __name__=="__main__":
    main()
