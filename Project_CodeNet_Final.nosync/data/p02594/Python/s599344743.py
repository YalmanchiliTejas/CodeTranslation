#atcoder template
def main():
    import sys
    imput = sys.stdin.readline
    #文字列入力の時は上記はerrorとなる。
    #ここにコード
    #input
    x = int(input())

    # %%
    #output
    if x >= 30:
        print("Yes")
    else:
        print("No")

    #N = 1のときなどcorner caseを確認！
if __name__ == "__main__":
    main()