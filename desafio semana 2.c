#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

int main (void)
{
	int escolaridade, analfabetos, seriesInicias, fundamental, eMedio, superior,
	pGraduacao=0, outros=0, totalMoradoresCasa = 0, totalMoradores=0, totalHomens=0, totalMulheres=0, 
	totalSeparamLixo=0, totalNaoSeparamLixo=0, totaisColetamAgua=0, totaisNaoColetamAgua=0, totalEntrevistados = 0;
	
	char entrevistado, entrevista, lixo, aguaChuva;
	float mediaRenda, mediaMoradoresPorCasa, renda=0, rendasSomadas=0, porcentagemHomens, porcentagemMulheres, porcentagemAnalfabetos, porcentagemSeriesInicias, porcentagemFundametal,
	porcentagemFundamental, porcentagemMedio, porcentagemSuperior, porcentagemGraduacao, porcentagemOutros;
	bool verificador;
	
	setlocale(LC_ALL, "Portuguese");
	printf("=======================================================================\n");
	printf("=================== Coletas de dados populacional =====================\n");
	
	do
	{
		verificador = false;
		//verifica��o se o entrevistado � homem ou mulher 
		printf("Se o entrevistado for homem, digite 'H', se for mulher digite 'F'.\n");
		while(verificador == false)
		{
			fflush(stdin);
			entrevistado = getchar();
			if(entrevistado == 'h' || entrevistado == 'H')
			{
				totalHomens++;
				totalEntrevistados++;
				verificador = true;
			}
			else if( entrevistado == 'f' || entrevistado == 'F')
			{
				totalMulheres++;
				totalEntrevistados++;
				verificador = true;
			}
			
			else
			{
				printf("Favor digitar novamente, H para homem e F para mulher.\n");
			}
		}
		
		
		//moradores por residencia 
		do{
			printf("Total de moradores da residencia: \n");
			scanf("%d", &totalMoradoresCasa);
		}while(totalMoradoresCasa == 0);
		totalMoradores = totalMoradores + totalMoradoresCasa;
		
		//renda familiar
		verificador = false;
		while(verificador == false){	
			printf("Qual a renda somada de todos os integrantes da moradia? \n");
			fflush(stdin);
			scanf("%f", &renda);
			if(renda <= 0)
			{
				verificador = false; 
			} else {
				verificador = true;
			}
			
			rendasSomadas = rendasSomadas + renda;
		}
		
		//separa��o de lixo
		verificador = false;
		while (verificador == false){
			printf("Na sua casa, � feito a separa��o do lixo? 'S' para sim e 'N' para n�o.\n");
			fflush(stdin);
			lixo = getchar();
			
			if(lixo == 'S' || lixo == 's')
			{
				totalSeparamLixo++;
				verificador = true;
			} else if (lixo == 'N' || lixo == 'n')
			{
				totalNaoSeparamLixo++;
				verificador = true;
			} else
			{
				printf("Apenas 'S' e 'N' s�o aceitos, favor digitar novamente.\n");
			}
			
		}
		
		//coleta �gua da chuva
		verificador = false;
		while(verificador == false){
			printf("Na sua casa � feito a coleta da �gua da chuva? 'S' para sim e 'N' para n�o.\n");
			fflush(stdin);
			aguaChuva = getchar();
			
			if(aguaChuva == 'S' || aguaChuva == 's')
			{
				verificador = true;
				totaisColetamAgua++;
			} else if (aguaChuva == 'N' || aguaChuva == 'n')
			{
				verificador = true;
				totaisNaoColetamAgua++;
			} else 
			{
				printf("Apenas 'S' e 'N' s�o aceitos, favor digitar novamente.\n");
			}
			
		}
		
		//maior nivel de escolaridade
		verificador = false;
		while (verificador == false){
		
			printf("Qual � o maior escolaridade dentro de sua residencia?\n");
			printf(" Digite 1 para analfabeto \n Digite 2 para s�ries inicias \n Digite 3 para ensino fundamental \n Digite 4 para ensino m�dio \n Digite 5 para ensino superior \n Digite 6 para p�s-gradu��o e 7 para outros\n");
			fflush(stdin);
			
			scanf("%d", &escolaridade);
				switch(escolaridade)
				{
					case 1: 
						analfabetos++;
						verificador = true;
						break;
					case 2:
						seriesInicias++;
						verificador = true;
						break;
					case 3:
						fundamental++;
						verificador = true;
						break;
					case 4:
						eMedio++;
						verificador = true;
						break;
					case 5:
						superior++;
						verificador = true;
						break;
					case 6:
						pGraduacao++;
						verificador = true;
						break;
					case 7:
						outros++;
						verificador = true;
						break;
					default:
						printf("Digite uma op��o v�lida\n");
				}
		}
		
		printf("Digite S para uma nova entrevista ou N para encerrar o programa.\n");
		fflush(stdin);
		entrevista = getchar();
		system("cls");
	} while(entrevista == 's' || entrevista == 'S'); 
	
	porcentagemHomens = (float) totalHomens / totalEntrevistados  * 100;
	porcentagemMulheres = (float) totalMulheres / totalEntrevistados * 100;
	mediaMoradoresPorCasa = totalMoradores / totalEntrevistados;  
	mediaRenda = rendasSomadas / totalMoradores;
	
	porcentagemAnalfabetos = (float) analfabetos / totalEntrevistados * 100;
	porcentagemSeriesInicias = (float) seriesInicias / totalEntrevistados * 100;
	porcentagemFundamental = (float) fundamental / totalEntrevistados * 100;
	porcentagemMedio = (float) eMedio / totalEntrevistados * 100;
	porcentagemSuperior = (float) superior / totalEntrevistados * 100;
	porcentagemGraduacao = (float) pGraduacao / totalEntrevistados * 100;
	porcentagemOutros = (float) outros / totalEntrevistados * 100;
	
	printf("Total de pessoas entrevistadas: %d\n", totalEntrevistados);
	printf("Total de homens entrevistados: %d\nTotal de mulheres entrevistadas: %d\n", totalHomens, totalMulheres);
	printf("Porcentagem de homens entrevistados: %.2f%% \nPorcentagem de mulheres entrevistadas: %.2f%%\n", porcentagemHomens, porcentagemMulheres);
	printf("M�dia de moradores por resindencia: %.2f\n", mediaMoradoresPorCasa);
	printf("M�dia de renda das f�milias: %.2f\n", mediaRenda);
	printf("Total de f�milias que separam o lixo: %d\nTotal de f�milias que n�o separam o lixo %d\n", totalSeparamLixo, totalNaoSeparamLixo);
	printf("Total de f�milias que coletam �gua da chuva: %d\nTotal de f�milias que n�o coletam �gua da chuva %d\n", totaisColetamAgua, totaisNaoColetamAgua);
	printf("Maiores escolaridades das residencias entrevistadas: \n");
	printf("\t Total analfabetos %d e porcentagem de analfabetos %.2f: \n", seriesInicias, porcentagemSeriesInicias);
	printf("\t Total de pessoas que concluiram as s�ries inicias %d, e sua porcentagem %.2f: \n", analfabetos, porcentagemAnalfabetos);
	printf("\t Total de pessoas que concluiram o fundamental %d, e sua porcentagem %.2f: \n", fundamental, porcentagemFundamental);
	printf("\t Total de pessoas que concluiram o endino m�dio %d, e sua porcentagem %.2f: \n", eMedio, porcentagemMedio);
	printf("\t Total de pessoas que concluiram o endino superior %d, e sua porcentagem %.2f: \n", superior, porcentagemSuperior);
	printf("\t Total de pessoas que concluiram a p�s gradua��o %d, e sua porcentagem %.2f: \n", pGraduacao, porcentagemGraduacao);
	printf("\t Total de pessoas que tem outro tipo de forma��o %d, e sua porcentagem %.2f: \n", outros, porcentagemOutros);
}
