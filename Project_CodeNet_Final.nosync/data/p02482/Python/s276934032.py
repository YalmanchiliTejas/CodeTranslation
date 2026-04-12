#coding:utf-8

def main():
    a, b = map(int, input().split())
    e = ["a ", " b"]
    if a < b:
        print("<".join(e))
    elif b < a:
        print(">".join(e))
    else:
        print("==".join(e))

if __name__ == "__main__":
    main()