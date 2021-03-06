#ifndef __CONSULTAR_H__
#define __CONSULTAR_H__

#include "excecao.h"
#include "painel.h"
#include "utilitarios.h"
#include "crud/operacoes_csv.h"

template <typename CLASSE>
void consultar(std::string enderecoArquivo, std::deque<std::string> caminho){
	
	Painel consulta;	
	OperacoesCSV<CLASSE> csv(enderecoArquivo);
    std::map<int, CLASSE> lista = csv.getLista();
    int selecao = 1;
    
    caminho.push_back("CONSULTAR");

	consulta.setTitulo("CONSULTAR");
	consulta.setCaminho(caminho);

	while(selecao != 0){

		try{
			std::cout << consulta;

			// Imprime a lista de funcionarios id-nome
	        typename std::map<int, CLASSE>::iterator it;
            for (it = lista.begin(); it != lista.end(); ++it)
                it->second.printIdNome();
            
            std::cout << "\n\t0. VOLTAR\n";
            std::cout << "\nSELECIONE UMA DAS OPÇÕES: ";
            std::cin >> selecao;
        
			// Tratamento de erro, caso o usuário insira texto em vez de números
			if(std::cin.fail()){
				std::cin.clear();
				std::cin.ignore(__INT_MAX__, '\n');
				throw Excecao("Valor inválido. Insira um valor númerico.");
			}

            painelDetalhes(selecao, lista, caminho);
		}
		catch(Excecao& e){
			consulta.setExcecao(e);
		}
			
	}
   
}

template <typename CLASSE>
void painelDetalhes(int id, std::map<int, CLASSE> &lista, std::deque<std::string> caminho){

    typename std::map<int, CLASSE>::iterator it;
    it = lista.find(id);

    if(it == lista.end())
        throw Excecao("O id informado é inválido. Tente novamente."); 
    
    caminho.push_back("DETALHES");
	std::string titulo = "DETALHES";	
	
	Painel detalhes(titulo, caminho);	

    int selecao = 1;
	while(selecao != 0){

		try{
			std::cout << detalhes;

            std::cout << it->second;
        
            std::cout << "\nPARA VOLTAR INSIRA O NÚMERO ZERO [0]: ";
            std::cin >> selecao;
        
			// Tratamento de erro, caso o usuário insira texto em vez de números
			if(std::cin.fail()){
				std::cin.clear();
				std::cin.ignore(__INT_MAX__, '\n');
				throw Excecao("Valor inválido. Insira um valor númerico.");
			}

		}
		catch(Excecao& e){
			detalhes.setExcecao(e);
		}
			
	}
}

#endif // __CONSULTAR_H__