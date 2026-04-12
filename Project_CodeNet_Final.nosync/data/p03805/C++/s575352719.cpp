#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 内部定数
#define D_ON			1										// 汎用フラグ - ON
#define D_OFF			0										// 汎用フラグ - OFF
#define D_VTX_MAX		8										// 最大頂点数

// 内部構造体 - 頂点情報
typedef struct Vtx {
	int mi1CVNo[D_VTX_MAX + 5];									// 接続頂点
	int miCCnt;													// 接続頂点数
} Vtx;

// 内部変数
static Vtx sz1Vtx[D_VTX_MAX + 5];								// 頂点
static int siVCnt;												// 頂点数
static int siPCnt;												// パス数

// 内部変数 - テスト用
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpT, *szpFpA;
#endif

// パス数セット
int
fSetPCnt(
	int piVNo					// <I> 接続頂点 1～
	, int *pipVNo				// <I> 接続済頂点
	, int piVCnt				// <I> 接続済頂点数
)
{
	int i;

	// 接続済チェック
	if (pipVNo[piVNo] != D_OFF) {
		return 0;
	}

	// 終了チェック
	if (piVCnt == siVCnt - 1) {
		siPCnt++;
		return 0;
	}

	// 接続
	pipVNo[piVNo] = D_ON;

	// 対象データ
	Vtx *lzpVtx = &sz1Vtx[piVNo];

	// 次の頂点へ
	for (i = 0; i < lzpVtx->miCCnt; i++) {
		fSetPCnt(lzpVtx->mi1CVNo[i], pipVNo, piVCnt + 1);
	}

	// 接続解除
	pipVNo[piVNo] = D_OFF;

	return 0;
}

// 実行メイン
int
fMain(
	int piTNo					// <I> テスト番号 1～
)
{
	int i;
	char lc1Buf[1024], lc1Out[1024];

	// データ初期化
	memset(sz1Vtx, 0, sizeof(sz1Vtx));							// 頂点
	siPCnt = 0;													// パス数

	// テストファイルオープン
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpT = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", piTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#endif

	// 頂点数・辺数取得
	int liECnt;
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d%d", &siVCnt, &liECnt);

	// 辺取得
	for (i = 0; i < liECnt; i++) {
		int liVNo1, liVNo2;
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
		fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
		sscanf(lc1Buf, "%d%d", &liVNo1, &liVNo2);

		// 接続頂点セット
		Vtx *lzpVtx = &sz1Vtx[liVNo1];
		lzpVtx->mi1CVNo[lzpVtx->miCCnt] = liVNo2;
		lzpVtx->miCCnt++;
		lzpVtx = &sz1Vtx[liVNo2];
		lzpVtx->mi1CVNo[lzpVtx->miCCnt] = liVNo1;
		lzpVtx->miCCnt++;
	}

	// パス数セット
	int li1VNo[D_VTX_MAX + 5];
	memset(li1VNo, D_OFF, sizeof(li1VNo));
	fSetPCnt(1, li1VNo, 0);

	// 結果セット
	sprintf(lc1Out, "%d\n", siPCnt);

	// 結果表示
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpA);
	if (strcmp(lc1Buf, lc1Out)) {
		siRes = -1;
	}
#else
	printf("%s", lc1Out);
#endif

	// テストファイルクローズ
#ifdef D_TEST
	fclose(szpFpT);
	fclose(szpFpA);
#endif

	// テスト結果
#ifdef D_TEST
	if (siRes == 0) {
		printf("OK %d\n", piTNo);
	}
	else {
		printf("NG %d\n", piTNo);
	}
#endif

	return 0;
}

int
main()
{

#ifdef D_TEST
	int i;
	for (i = D_TEST_SNO; i <= D_TEST_ENO; i++) {
		fMain(i);
	}
#else
	fMain(0);
#endif

	return 0;
}

