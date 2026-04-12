def a(s):
 
    return "Yes" if s.count("A") != 0 and s.count("B") != 0 else "No"
 
 
def main():
    s = str(input())
    print(a(s))
 
if __name__ == '__main__':
    main()